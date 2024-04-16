// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FGInventoryComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ShirubaFifoContainerLogic.generated.h"

/**
 * 
 */
UCLASS()
class FIFOCONTAINERS_API UShirubaFifoContainerLogic : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "FIFO")
	static bool FifoFactoryGrabOutput(FInventoryItem& out_item, float& out_OffsetBeyond, UFGInventoryComponent* inventory, TSubclassOf< UFGItemDescriptor > type);
	
};
