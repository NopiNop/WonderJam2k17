// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "JSONParser.generated.h"

UCLASS()
class MYPROJECT_API AJSONParser : public AActor
{
	GENERATED_BODY()
	AJSONParser();

	UFUNCTION(BlueprintPure, Category = "JSON")
		static FString GetFieldValue(FString JsonRaw, FString Field);
};
