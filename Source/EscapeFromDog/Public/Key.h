// copyright 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Key.generated.h"

UCLASS()
class ESCAPEFROMDOG_API ADoorKey : public AActor
{
	GENERATED_BODY()

public:
	ADoorKey();

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Mesh;
};
