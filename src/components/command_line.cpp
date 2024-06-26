#include <curses.h>

#include "components/command_line.hpp"

namespace bff {

CommandLine::CommandLine(int y, int x) : Window(1, COLS, y, x) {}

string CommandLine::get_command() {
  string buf;
  char c = ':';

  curs_set(1);

  do {
    switch (c) {
    case (char)KEY_BACKSPACE:
      buf.pop_back();
      break;
    default:
      buf.push_back(c);
      break;
    }

    win_clear();
    win_mvprint(0, 0, "%s", buf.c_str());
    win_refresh();
  } while ((c = getch()) != '\n');

  win_clear();
  win_refresh();
  curs_set(0);

  return buf;
}

} // namespace bff
