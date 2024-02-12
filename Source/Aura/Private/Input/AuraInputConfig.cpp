


#include "Input/AuraInputConfig.h"
#include "InputAction.h"
const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FAuraInputAction& Action : AbilityInputAction)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{

			return Action.InputAction;
		}

	}
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't Find Ability Input Action InputTag[%s] InputConfig[%s]"),*InputTag.ToString(),*GetNameSafe(this));
	}
	return nullptr;
}
