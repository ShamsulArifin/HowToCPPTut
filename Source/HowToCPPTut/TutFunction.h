// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TutFunction.generated.h"

/**
 * 
 */
UCLASS()
class HOWTOCPPTUT_API UTutFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Level")
		static void PlayLevel();

	UFUNCTION(BlueprintCallable, Category = "Level")
		static void OpenLevelBlueprint();
};
