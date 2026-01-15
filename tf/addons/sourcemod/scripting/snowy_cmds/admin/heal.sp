void PerformHeal(int client, int target)
{
    int max = GetEntProp(target, Prop_Data, "m_iMaxHealth");
    
    SetEntityHealth(target, max);
    // PrintToChatAll("Heal %N\nHealth: %i\nMax: %i", target_name, GetClientHealth(target_list[i]), GetEntProp(target_list[i], Prop_Send, "m_iMaxHealth"));
    // PrintToChatAll("Heal %N\nHealth: %i\nMax: %i", target_name, GetClientHealth(target_list[i]), GetEntProp(target_list[i], Prop_Send, "m_iMaxHealth"));
}

public Action Command_Heal(int client, int args)
{
    if ( args < 1 )
    {
        Snowy_ReplyToCommand(client, "Usage: sm_heal <player>");
	    return Plugin_Handled;
    }

	char arg[65];
	GetCmdArg(1, arg, sizeof(arg));
	
	char target_name[MAX_TARGET_LENGTH];
	int target_list[MAXPLAYERS], target_count;
	bool tn_is_ml;
	
	if ((target_count = ProcessTargetString(
			arg,
			client,
			target_list,
			MAXPLAYERS,
			COMMAND_FILTER_ALIVE,
			target_name,
			sizeof(target_name),
			tn_is_ml)) <= 0)
	{
		ReplyToTargetError(client, target_count);
		return Plugin_Handled;
	}
	
	for (int i = 0; i < target_count; i++)
	{
        PerformHeal(client, target_list[i]);
    }
	return Plugin_Handled;
}