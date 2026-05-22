// copyright 2026 sabaka-chabaka

#include "Key.h"

ADoorKey::ADoorKey()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}