#ifndef _MENU_H_
#define _MENU_H_

void createMenu(char menu, char* selection);
void menuInput(int input, char* selection, char* menu, struct Level* level, struct Player* player, struct Ball* ball);
void moveCursor(int input, char* selection, char min, char max);

#endif /* _MENU_H_ */
