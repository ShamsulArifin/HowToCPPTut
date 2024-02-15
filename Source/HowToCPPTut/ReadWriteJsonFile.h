// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadWriteJsonFile.generated.h"


class FJsonObject;

USTRUCT(BlueprintType, Category = "Read Write Json")
struct FDataStruct
{
	GENERATED_BODY()

	//These variables are visible in both Blueprint and in Json
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Read Write Json")
		FString MyString = "Llama";
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Read Write Json")
		bool Mybool = true;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Read Write Json")
		float Myfloat = 123.356f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Read Write Json")
		int MyInt = 123;

	//These variables are not visible in Blueprint, but are still visible in Json
public:
	UPROPERTY()
		FVector MyVector = { 1.0f, 2.0f, 3.0f };
	UPROPERTY()
		FRotator MyRotator = { 90.0f, 180.0f, 270.0f };
	UPROPERTY()
		FTransform MyTransform;

	//This variable is not visible in Blueprint or Json
public:
	FString MyOtherString = "This variable will not be in the json because it's not flagged as an UPROPERTY()";
};

UCLASS()
class HOWTOCPPTUT_API UReadWriteJsonFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*
	 * Open a json file, read it's content and convert it to a JsonObject
	 *
	 * @param JsonFilePath		The path of your json file: "C:/Temp/MyJson.json"
	 * @param bOutSuccess		If the action was success or not
	 * @param OutInfoMessage	More information about the action's result
	 *
	 * @return The JsonObject content of your json file
	 */
	UFUNCTION(BlueprintCallable, Category = "Read Write Json")
		static FDataStruct ReadStructFromJsonFile(FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage);

	/*
	 * Convert your JsonObject to a string, create a json file and dump the string in it
	 *
	 * @param JsonFilePath		The path of your json file: "C:/Temp/MyJson.json"
	 * @param Struct			The struct want to write in the file
	 * @param bOutSuccess		If the action was success or not
	 * @param OutInfoMessage	More information about the action's result
	 */
	UFUNCTION(BlueprintCallable, Category = "Read Write Json")
		static void WriteStructJsonFile(FString JsonFilePath, FDataStruct Struct, bool& bOutSuccess, FString& OutInfoMessage);



	
public:
	/*
	 * Open a json file, read it's content and convert it to a JsonObject
	 *
	 * @param JsonFilePath		The path of your json file: "C:/Temp/MyJson.json"
	 * @param bOutSuccess		If the action was success or not
	 * @param OutInfoMessage	More information about the action's result
	 *
	 * @return The JsonObject content of your json file
	 */
	static TSharedPtr<FJsonObject> ReadJson(FString JsonFilePath, bool& bOutSuccess, FString& OutInfoMessage);

	/*
	 * Convert your JsonObject to a string, create a json file and dump the string in it
	 *
	 * @param JsonFilePath		The path of your json file: "C:/Temp/MyJson.json"
	 * @param JsonObject		The JsonObject to write in the file
	 * @param bOutSuccess		If the action was success or not
	 * @param OutInfoMessage	More information about the action's result
	 */
	static void WriteJson(FString JsonFilePath, TSharedPtr<FJsonObject> JsonObject, bool& bOutSuccess, FString& OutInfoMessage);
};
