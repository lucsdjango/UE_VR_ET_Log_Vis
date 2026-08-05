// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TSVLogger.generated.h"

UCLASS()
class VRETLOGGER_API ATSVLogger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATSVLogger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	TMap<FString, FString> LogColumns;
	TMap<FString, FString> ResetColumns;
	IFileHandle* fileHandle;
	double startSeconds;
	bool Logging;
	void LogLabels();
	bool Async;
	void Log();


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "TSV Logger")
	void AddEntry(FString k, FString defVal = "", bool resetEachFrame = false);
	UFUNCTION(BlueprintCallable, Category = "TSV Logger")
	void UpdateEntry(FString k, FString v = "");
	UFUNCTION(BlueprintCallable, Category = "TSV Logger")
	void UpdateVector(FString k, FVector v);
	UFUNCTION(BlueprintCallable, Category = "TSV Logger")
	void UpdateDouble(FString k, double v);
	UFUNCTION(BlueprintCallable, Category = "TSV Logger")
	void UpdateFloat(FString k, float v);
	UFUNCTION(BlueprintCallable, Category = "TSV Logger")
	void UpdateInt(FString k, int v);
	UFUNCTION(BlueprintCallable, Category = "TSV Logger")
	void UpdateQuat(FString k, FQuat q);
	UFUNCTION(BlueprintCallable, Category = "TSV Logger")
	void InitOrReset();
	UFUNCTION(BlueprintCallable, Category = "TSV Logger")
	void StartLogging(FString id, bool async = false);
	UFUNCTION(BlueprintCallable, Category = "TSV Logger")
	void AsyncLog();

};
