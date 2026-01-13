#if defined _snowy_commands_included
  #endinput
#endif
#define _snowy_commands_included

void CommandUsage(int client, const char[] message)
{
    if (client == 0)
    {
        ReplyToCommand(client, CONS_PREFIX ..." Usage: %s", message);
    } else {
        ReplyToCommand(client, CHAT_PREFIX ..." Usage: %s", message);
    }
}
