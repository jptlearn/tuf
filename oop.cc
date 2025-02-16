#include <iostream>
using namespace std;

// class Player {
//   public:
//   int x, y;
//   int speed;

//   void Move(int xa, int ya) {
//     x += xa * speed;
//     y += ya * speed; 
//   }
// };

// int main() {
//   Player player;
//   player.x = 5;
//   player.y = 6;
//   player.speed = 22;
//   player.Move(-2, -3);
// }

class Log {
  public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;

  private:
    int m_LogLevel = LogLevelInfo;

  public:
    void SetLevel(int level){
      m_LogLevel = level;
    }
    void Warn(const char* message) {
      cout << "[WARNING]: " << message << endl;
    }
};

int main(){
  Log log;
  log.SetLevel(log.LogLevelWarning);
  log.Warn("Hello");
}