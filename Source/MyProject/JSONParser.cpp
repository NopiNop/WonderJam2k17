// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "JSONParser.h"


// Sets default values
AJSONParser::AJSONParser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FString AJSONParser::GetFieldValue(FString JsonRaw, FString Field)
{
	TSharedPtr<FJsonObject> JsonParsed;
	FString FieldValue;

	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonRaw);

	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))
	{
		FieldValue = JsonParsed->GetStringField(Field);
	}

	return FieldValue;
}

