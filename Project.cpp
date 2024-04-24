#include <ncurses.h>

int main() {
  // Khởi tạo Ncurses
  initscr();

  // Tắt chế độ echo
  noecho();

  // Tắt dỡ phím backspace
  cbreak();

  // Vẽ khung
  attron(A_REVERSE); // Bật in đậm ngược
  printw("+-------------------------------------------------------+\n");
  attroff(A_REVERSE); // Tắt in đậm ngược

  // In ra dòng chữ
  printw("| Nhập tên của bạn: ");

  // Lấy tên người dùng
  char name[100];
  getstr(name);

  // In lời chào
  printw("\nChào mừng, %s!\n", name);

  // Dừng chương trình và dọn dẹp Ncurses
  getch();
  endwin();

  return 0;
}
