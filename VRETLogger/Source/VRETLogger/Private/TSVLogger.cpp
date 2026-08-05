
// Fill out your copyright notice in the Description page of Project Settings.


#include "TSVLogger.h"

#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/Paths.h"


// Constructor
ATSVLogger::ATSVLogger()
{
	
	PrimaryActorTick.bCanEverTick = true; // Set this actor to call Tick() every frame. 
	PrimaryActorTick.TickGroup = TG_PostUpdateWork; // as late as possible

	// Initialize TMaps
	LogColumns = TMap<FString, FString>();
	ResetColumns = TMap<FString, FString>();
	Logging = false;


}

// Called when the game starts or when spawned
void ATSVLogger::BeginPlay()
{
	Super::BeginPlay();


	startSeconds = FPlatformTime::Seconds();
	
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
}

// Called every frame
void ATSVLogger::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	FString s = (Logging ? "true" : "false");
	
	if (Logging == true)
	{
		UpdateDouble("time", FPlatformTime::Seconds() - startSeconds); 
		double utcTime = FDateTime::UtcNow().ToUnixTimestampDecimal();
		UpdateDouble("UnixTime", utcTime); 
		

		if (!Async && Logging && fileHandle)
		{
			Log();
		}
		// Reseting to deafault values for columns added with argument resetEachFrame = true
		for (auto& Elem : ResetColumns)
		{
			UpdateEntry(Elem.Key, Elem.Value);
		}
	}

}

void ATSVLogger::LogLabels()
{
	if (!fileHandle)
	{
		return;
	}
	FString Line = "";
	for (auto& Elem : LogColumns)
	{
		Line.Append(Elem.Key + "\t");
	}
	Line.Append("\n");
	fileHandle->Write((const uint8*)TCHAR_TO_ANSI(*Line), Line.Len());
	UE_LOG(LogTemp, Warning, TEXT("Labels written"));
}

// Called once every tick after logging started, unless async logging mode enabled
void ATSVLogger::Log()
{

	FString line = "";
	for (auto& Elem : LogColumns)
	{
		line.Append(Elem.Value + "\t");
	}
	line.Append("\n");
	fileHandle->Write((const uint8*)TCHAR_TO_ANSI(*line), line.Len());

}

void ATSVLogger::AsyncLog()
{
	if (Async)
	{
		UpdateDouble("time", FPlatformTime::Seconds() - startSeconds);
		double utcTime = FDateTime::UtcNow().ToUnixTimestampDecimal();
		UpdateDouble("UnixTime", utcTime);
		Log();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Attempted Async log when in sync mode! "));

	}
}

// Columns should be added before StartLogging is called
void ATSVLogger::AddEntry(FString k, FString v, bool resetEachFrame)
{
	LogColumns.Add(k, v);

	if (resetEachFrame)
		ResetColumns.Add(k, v);
}

void ATSVLogger::UpdateEntry(FString k, FString v)
{
	if (LogColumns.Contains(k))
		LogColumns[k] = v;
	else
		UE_LOG(LogTemp, Warning, TEXT("Attempted update of missing log-key: "));
}

void ATSVLogger::UpdateVector(FString k, FVector v)
{
	UpdateEntry(k, FString::SanitizeFloat(v.X) + "," + FString::SanitizeFloat(v.Y) + "," + FString::SanitizeFloat(v.Z));
}

void ATSVLogger::UpdateDouble(FString k, double v)
{
	UpdateEntry(k, FString::SanitizeFloat(v));
}

void ATSVLogger::UpdateFloat(FString k, float v)
{
	UpdateEntry(k, FString::SanitizeFloat(v));
}

void ATSVLogger::UpdateInt(FString k, int v)
{
	UpdateEntry(k, FString::FromInt(v));
}

void ATSVLogger::UpdateQuat(FString k, FQuat q)
{
	UpdateEntry(k, FString::SanitizeFloat(q.X) + "," + FString::SanitizeFloat(q.Y) + "," + FString::SanitizeFloat(q.Z)+ "," + FString::SanitizeFloat(q.W));
}

void ATSVLogger::InitOrReset()
{
	LogColumns = TMap<FString, FString>();
	ResetColumns = TMap<FString, FString>();
	Logging = false;
	AddEntry("time");
	AddEntry("UnixTime");
	//AddEntry("test", "default", true);
}

// Called after adding columns with calls to AddEntry(..). Tab separated file is created with id argument as file name prefix.
void ATSVLogger::StartLogging(FString id, bool async)
{
	UE_LOG(LogTemp, Warning, TEXT("StartLog called"));
	
	FString ProjectSavedDirectory = FPaths::ProjectContentDir() + "/VRETLogs";
	IPlatformFile& platformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (!platformFile.DirectoryExists(*ProjectSavedDirectory))
	{
		platformFile.CreateDirectory(*ProjectSavedDirectory);
	}
	UE_LOG(LogTemp, Warning, TEXT("FilePaths: ProjectSavedDir: %s"), *ProjectSavedDirectory);
	
	
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();
	const TCHAR* directory = *ProjectSavedDirectory.Append("//").Append(*id).Append(".tsv");
	fileHandle = file.OpenWrite(directory);
	LogLabels();
	Async = async;
	Logging = true;
}

// Called when stopping run, ensuring buffer is written to file and file writer is closed.
void ATSVLogger::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UE_LOG(LogTemp, Warning, TEXT("EndPlay"));
	if (fileHandle) // close file writer after writing buffer
	{
		fileHandle->Flush(true);
		delete fileHandle;
		UE_LOG(LogTemp, Warning, TEXT("file closed"));
	}

	Super::EndPlay(EndPlayReason);
}




 