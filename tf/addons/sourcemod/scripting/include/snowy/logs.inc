#if defined _snowy_logs_included
  #endinput
#endif
#define _snowy_logs_included

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