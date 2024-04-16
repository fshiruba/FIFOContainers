// Fill out your copyright notice in the Description page of Project Settings.


#include "ShirubaFifoContainerLogic.h"
#include <vector>
#include "FGInventoryComponent.h"


bool UShirubaFifoContainerLogic::FifoFactoryGrabOutput(FInventoryItem& out_item, float& out_OffsetBeyond, UFGInventoryComponent* inventory, TSubclassOf < UFGItemDescriptor > type)
{
	out_item = FInventoryItem::NullInventoryItem;

	if (inventory->IsEmpty())
	{
		//UE_LOG(LogTemp, Warning, TEXT("Inventory is Empty!"));
		return false;
	}

	int32 invSize = inventory->GetSizeLinear();

	FInventoryStack out_stack;


	//avoid empty indexes at the start
	std::vector<int> emptySpaces;

	int j = 0;
	while (j != invSize)
	{
		if (inventory->IsIndexEmpty(j))
		{
			emptySpaces.push_back(j);
		}
		else
		{
			if (emptySpaces.empty() == false)
			{
				if (inventory->GetStackFromIndex(j, out_stack))
				{
					inventory->AddStackToIndex(emptySpaces[0], out_stack);
					inventory->RemoveAllFromIndex(j);
					emptySpaces.erase(emptySpaces.begin());
				}
			}
		}

		j = j + 1;
	}

	out_item = FInventoryItem::NullInventoryItem;
	emptySpaces.clear();

	if (inventory->GetStackFromIndex(0, out_stack))
	{
		if (out_stack.NumItems > 0)
		{
			inventory->RemoveFromIndex(0, 1);
			out_item = out_stack.Item;
			//UE_LOG(LogTemp, Warning, TEXT("Dispatching index: %d"), i);
			return true;
		}
	}
		
	return false;
}
