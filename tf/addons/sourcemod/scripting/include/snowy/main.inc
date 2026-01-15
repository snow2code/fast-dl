#if defined _snowy_included
  #endinput
#endif
#define _snowy_included

//////////////////////// CHAT ///////////////////////
#define CHAT_PREFIX 	    "\x0700FF90[Snowy]\x01"
#define CONS_PREFIX 	    "[Snowy]"
#define SM_CHAT_PREFIX 	    "\x07FFA500[SM]\x01"
#define SM_CONS_PREFIX 	    "[SM]"
/////////////////////////////////////////////////////

stock void Snowy_ReplyToCommand(int client, const char[] fmt, any ...)
{
    char buffer[256];
    VFormat(buffer, sizeof(buffer), fmt, 3);

    if ( client == 0 )
    {
        ReplyToCommand(client, "%s %s", CONS_PREFIX, buffer);
    } else {
        ReplyToCommand(client, "%s %s", CHAT_PREFIX, buffer);
    }
}

stock void SendMessageToAll(const char[] fmt, any ...)
{
    char buffer[256];

    // 2 = index where varargs start (fmt is arg 1)
    VFormat(buffer, sizeof(buffer), fmt, 2);

    PrintToChatAll("%s", buffer);
    PrintToServer("%s", buffer);
}

stock void SendMessageToClient(int client, const char[] fmt, any ...)
{
    char buffer[256];
    VFormat(buffer, sizeof(buffer), fmt, 3);

    PrintToChat(client, "%s %s", CHAT_PREFIX, buffer);
}
