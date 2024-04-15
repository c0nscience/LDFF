// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LDFF : ModuleRules
{
	public LDFF(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"ApplicationCore",
			"Engine",
			"GameplayTags",
			"GameplayTasks",
			"GameplayAbilities",
			"NavigationSystem",
			"AIModule",
			"Niagara",
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"InputCore",
			"UMG",
			"CommonUI",
			"CommonInput",
			"EnhancedInput",
		});
	}
}