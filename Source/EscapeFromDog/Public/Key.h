// copyright 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Key.generated.h"

UCLASS()
class ESCAPEFROMDOG_API AKey : public AActor
{
	GENERATED_BODY()

public:
	AKey();

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere)
	bool bCollected;
};