// Fill out your copyright notice in the Description page of Project Settings.


#include "TutFunction.h"

#include "LevelEditor.h"
#include "UnrealEdGlobals.h"
#include "Editor/UnrealEdEngine.h"
#include "Engine/LevelScriptBlueprint.h"

void UTutFunction::PlayLevel()
{
	FLevelEditorModule& LevelEditorModule = FModuleManager::GetModuleChecked<FLevelEditorModule>(TEXT("LevelEditor"));
	FRequestPlaySessionParams SessionParams;
	SessionParams.DestinationSlateViewport = LevelEditorModule.GetFirstActiveViewport();
	GUnrealEd->RequestPlaySession(SessionParams);
}

void UTutFunction::OpenLevelBlueprint()
{
	ULevelScriptBlueprint* LevelScriptBlueprint = GEditor->GetEditorWorldContext().World()->PersistentLevel->GetLevelScriptBlueprint();
	const bool bOpenWorldCentric = false;
	GEditor->GetEditorSubsystem<UAssetEditorSubsystem>()->OpenEditorForAsset(
		LevelScriptBlueprint,
		bOpenWorldCentric ? EToolkitMode::WorldCentric : EToolkitMode::Standalone);
}
