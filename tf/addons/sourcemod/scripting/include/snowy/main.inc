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

void Snowy_LogWithChatMsgToAll(const char[] fmt, any ...)
{
    char buffer[256];
    char date[64];
    char filepath[PLATFORM_MAX_PATH];

    // 2 = index where varargs start (fmt is arg 1)
    VFormat(buffer, sizeof(buffer), fmt, 2);

    // Time format
    FormatTime(date, sizeof(date), "%d-%m-%Y", GetTime()); // %H-%M-%H:%:%S
    Format(filepath, sizeof(filepath), "logs_snowy/%s.txt", date);

    SendMessageToAll(buffer);
    LogToFile(filepath, "%s", buffer);
}

void Snowy_Log(const char[] fmt, any ...)
{
    char buffer[256];
    char date[64];
    char filepath[PLATFORM_MAX_PATH];

    // 2 = index where varargs start (fmt is arg 1)
    VFormat(buffer, sizeof(buffer), fmt, 2);

    // Time format
    FormatTime(date, sizeof(date), "%d-%m-%Y", GetTime()); // %H-%M-%H:%:%S
    Format(filepath, sizeof(filepath), "logs_snowy/%s.txt", date);

    LogToFile(filepath, "%s", buffer);
}

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

stock void SendMessageToAll_Log(const char[] fmt, any ...)
{
    char buffer[256];

    // 2 = index where varargs start (fmt is arg 1)
    VFormat(buffer, sizeof(buffer), fmt, 2);

    PrintToChatAll("%s", buffer);
    PrintToServer("%s", buffer);
}

stock void SendMessageToAll(const char[] fmt, any ...)
{
    char buffer[256];

    // 2 = index where varargs start (fmt is arg 1)
    VFormat(buffer, sizeof(buffer), fmt, 2);

    PrintToChatAll("%s", buffer);
}

stock void SendMessageToClient(int client, const char[] fmt, any ...)
{
    char buffer[256];
    VFormat(buffer, sizeof(buffer), fmt, 3);

    PrintToChat(client, "%s %s", CHAT_PREFIX, buffer);
}
