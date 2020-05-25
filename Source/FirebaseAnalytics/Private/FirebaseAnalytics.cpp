// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FirebaseAnalytics.h"
#include "FirebaseAnalyticsProvider.h"

#define LOCTEXT_NAMESPACE "FFirebaseAnalyticsModule"

void FFirebaseAnalytics::StartupModule()
{
	FirebaseAnalyticsProvider = MakeShareable(new FFirebaseAnalyticsProvider());
}

void FFirebaseAnalytics::ShutdownModule()
{
}

inline FFirebaseAnalytics& FFirebaseAnalytics::Get()
{
	return FModuleManager::LoadModuleChecked<FFirebaseAnalytics>("FirebaseAnalytics");
}

TSharedPtr<IAnalyticsProvider> FFirebaseAnalytics::CreateAnalyticsProvider(const FAnalyticsProviderConfigurationDelegate & GetConfigValue) const
{
	return FirebaseAnalyticsProvider;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFirebaseAnalytics, FirebaseAnalytics)
