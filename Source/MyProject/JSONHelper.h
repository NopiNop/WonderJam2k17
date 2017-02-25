// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "JsonObjectConverter.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "JSONHelper.generated.h"

USTRUCT(BlueprintType)
struct FAnswer
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
		FString Answer;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
		float Power;

};

USTRUCT(BlueprintType)
struct FRequest
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
		FString Question;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
		TArray<FAnswer> AnswerParam;
};

USTRUCT(BlueprintType)
struct FJsonData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
		TArray<FRequest> JsonData;
};

USTRUCT(BlueprintType)
struct FCharacterInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
		int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
		FString Question;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
		TArray<FAnswer> Answers;
};

/**
 * 
 */
UCLASS()
class MYPROJECT_API UJSONHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	//UFUNCTION(BlueprintPure, Category = "JSON")
	//	static bool FileLoadString(FString FileNameA, FString& SaveTextA);

	UFUNCTION(BlueprintPure, Category = "JSON")
		static FString GetFieldValue(FString JsonRaw, FString Field);

	UFUNCTION(BlueprintPure, Category = "JSON")
		static TArray<FCharacterInfo> ParseJSONFile(FString JsonRaw);
	
	//UFUNCTION(BlueprintPure, Category = "JSON")
		TArray<TSharedPtr<FJsonValue>>  GetArrayField(FString JsonRaw, const FString& FieldName);
};
