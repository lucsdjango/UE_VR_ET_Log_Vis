// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TSVLogger.h"
#include "VRLogger.generated.h"

UCLASS()
class VRETLOGGER_API AVRLogger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVRLogger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UStaticMeshComponent* DebugShape;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "VR Logger")
	void StartLogging(FString id);
	UFUNCTION(BlueprintCallable, Category = "VR Logger")
	void SetDebugShape(UStaticMeshComponent* shape);
	UFUNCTION(BlueprintCallable, Category = "VR Logger")
	void UpdateETData(float deltaTime, FVector headPos, FQuat headRot, FVector gazeOrigin, FVector dir, float conf, FVector fixPoint, bool lBlink, bool rBlink, float lPupil, float rPupil, FVector lOrigin, FVector lDir, FVector rOrigin, FVector rDir, bool valid);
	UFUNCTION(BlueprintCallable, Category = "VR Logger")
	void UpdateHits(FVector pos, FString name);
	UFUNCTION(BlueprintCallable, Category = "VR Logger")
	void CalculateAndUpdateHits(FVector pos, FVector dir, FString filterTag);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VR Logger")
	ATSVLogger* Logger;
	TArray<FString> Labels;
	

};
