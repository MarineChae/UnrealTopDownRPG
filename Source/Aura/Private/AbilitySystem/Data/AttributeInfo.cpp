#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttiributeTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTag(AttiributeTag))
		{
			return Info;
		}
	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("can't Find info for AttributeTag[%s] on AttribuiteInfo[%s]"), *AttiributeTag.ToString(), *GetNameSafe(this));
	}

	return FAuraAttributeInfo();
}
