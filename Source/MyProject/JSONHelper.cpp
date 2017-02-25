// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "JSONHelper.h"




//bool UJSONHelper::FileSaveString(FString SaveTextB, FString FileNameB)
//{
//	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameDir() + FileNameB));
//}
//
//bool UJSONHelper::FileLoadString(FString FileNameA, FString& SaveTextA)
//{
//	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameDir() + FileNameA));
//}
//
//FString UJSONHelper::GetStringField(const FString & FieldName)
//{
//	return FJsonObject::GetStringField()
//}

FString UJSONHelper::GetFieldValue(FString JsonRaw, FString Field)
{
	TSharedPtr<FJsonObject> JsonParsed;
	FString FieldValue = "NULL";

	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);

	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
		FieldValue = JsonParsed->GetStringField(Field);
	}

	return FieldValue;
}

TArray<TSharedPtr<FJsonValue>> UJSONHelper::GetArrayField(FString JsonRaw, const FString& FieldName)
{
	TSharedPtr<FJsonObject> JsonParsed;
	TArray<TSharedPtr<FJsonValue>>  FieldValue;

	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);

	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
		FieldValue = JsonParsed->GetArrayField(FieldName);
	}

	return FieldValue;
}

TArray<FCharacterInfo> UJSONHelper::ParseJSONFile(FString JsonRaw)
{
	TArray<FCharacterInfo> data;
	if (!FJsonObjectConverter::JsonArrayStringToUStruct(JsonRaw, &data, 0, 0))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, "UJSONHelper::ParseJSONFile Fail");
	}

	TArray<FRequest> JsonData;
	/*if (!FJsonObjectConverter::JsonArrayStringToUStruct<FRequest>(
		JsonRaw,
		&JsonData,
		0, 0))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, "Fail");
	}*/

	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::FromInt(JsonData.Num()/*[0].JsonData.Num()*/));
	return data;
}