// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HowToCPPTut : ModuleRules
{
	public HowToCPPTut(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange
		(
			new string[] 
				
			{ 
				// Default Modules
				"Core", 
				"CoreUObject", 
				"Engine", 

				// New Modules
				"Json",
				"JsonUtilities",
				"LevelSequence",
				"Niagara",
				"AssetRegistry",
				"MovieScene",
				"MovieSceneTracks",
				"AIModule",

				// New Modules - Editor Only
				"AssetTools",
				"UnrealEd",
				"MaterialEditor",
				"KismetCompiler",
				"SequencerScriptingEditor",
				"MovieSceneTools",
				"MovieSceneCapture",
				"AVIWriter",
				"LevelEditor",
			}
		);

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
