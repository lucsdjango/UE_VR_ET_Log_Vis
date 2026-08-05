// Fill out your copyright notice in the Description page of Project Settings.


#include "VRLogger.h"

#include "CollisionQueryParams.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "Engine/HitResult.h"
#include "Engine/World.h"

// Sets default values
AVRLogger::AVRLogger()
{
 	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;
	Labels = { TEXT("Valid"),TEXT("GazeOrigin"), TEXT("GazeDir"), TEXT("Conf"), TEXT("FixPoint"), TEXT("LBlink"), TEXT("RBlink"), TEXT("LPupil"), TEXT("RPupil"), TEXT("LOrigin"),TEXT("LDir"),TEXT("ROrigin"),TEXT("RDir"),TEXT("HitPos"),TEXT("HitName") };
	if(GEngine)
    	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));	
}

// Called when the game starts or when spawned
void AVRLogger::BeginPlay()
{
	Super::BeginPlay();

	// Fixed framerate is not working realiably in VR preview mode.
	//GEngine->FixedFrameRate = 90.0;
	//GEngine->bUseFixedFrameRate = true;
	
}

// Called every frame
void AVRLogger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Initializes TSV Logger object and adds columns for variables to log. 
void AVRLogger::StartLogging(FString id)
{
	Logger->InitOrReset();
	Logger->AddEntry("FPS","", true);
	Logger->AddEntry("HeadPos", "", true);
	Logger->AddEntry("HeadRot", "", true);
	
	for (FString label : Labels) {
		Logger->AddEntry(label);
	}

	Logger->StartLogging(id, false);
}


void AVRLogger::SetDebugShape(UStaticMeshComponent* shape)
{
	DebugShape = shape;
}


// Called each tick. See VRETLogging blueprint.
void AVRLogger::UpdateETData(float deltaTime, FVector headPos, FQuat headRot, FVector gazeOrigin, FVector dir, float conf, FVector fixPoint, bool lBlink, bool rBlink, float lPupil, float rPupil, FVector lOrigin, FVector lDir, FVector rOrigin, FVector rDir, bool valid)
{

	Logger->UpdateFloat("FPS", 1.0f / deltaTime);

	if (!valid)
	{
		Logger->UpdateEntry("Valid", "F");
	}
	else
	{
		Logger->UpdateEntry("Valid", "T");
		Logger->UpdateVector("HeadPos", headPos);
		Logger->UpdateQuat("HeadRot", headRot);
		Logger->UpdateVector("GazeOrigin", gazeOrigin);
		Logger->UpdateVector("GazeDir", dir);
		Logger->UpdateFloat("Conf", conf);
		Logger->UpdateVector("FixPoint", fixPoint);
		Logger->UpdateEntry("LBlink", (lBlink ? "T" : "F"));
		Logger->UpdateEntry("RBlink", (rBlink ? "T" : "F"));
		Logger->UpdateFloat("LPupil", lPupil);
		Logger->UpdateFloat("RPupil", rPupil);
		Logger->UpdateVector("LOrigin", lOrigin);
		Logger->UpdateVector("LDir", lDir);
		Logger->UpdateVector("ROrigin", rOrigin);
		Logger->UpdateVector("RDir", rDir);

		CalculateAndUpdateHits(gazeOrigin, dir, "");

	}
}

void AVRLogger::UpdateHits(FVector pos, FString name)
{
	Logger->UpdateVector("HitPos", pos);
	Logger->UpdateEntry("HitName", name);
}

void AVRLogger::CalculateAndUpdateHits(FVector pos, FVector dir, FString filterTag)
{
	FCollisionQueryParams TraceParams = FCollisionQueryParams(FName(TEXT("ETTest")), false, this);
	TArray<FHitResult> Hits;
	FString HitsString = "";


	GetWorld()->LineTraceMultiByChannel(Hits, pos, dir * 9999999.9f, ECollisionChannel::ECC_Visibility, TraceParams);
	FVector FirstHitPos = FVector::Zero();

	// Collision responses -> visibility should be set to overlap not to block objects behind. TODO: Does not work with movable objects. 
	for (auto& Hit : Hits)
	{

		if (Hit.GetActor())
		{
			if (FirstHitPos.IsZero())
			{
				FirstHitPos = Hit.Location;
			}
			else
			{
				HitsString.Append(", ");
			}
			
			//UE_LOG(LogTemp, Warning, TEXT(" These are the hits : %s"), *Hit.GetActor()->GetName());
			HitsString.Append(*Hit.GetActor()->GetName());

		}
	}
	DebugShape->SetWorldLocation(FirstHitPos);
	UpdateHits(FirstHitPos, HitsString);
}

