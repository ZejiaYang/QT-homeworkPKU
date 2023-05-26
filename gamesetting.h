#ifndef GAMESETTING_H
#define GAMESETTING_H

#include <QWidget>

class GameSetting //记录最高分
{
private:
    GameSetting();
public:
    int highscore = 0;
    static GameSetting* getInstance()
    {
        //是一个static的对象
        static GameSetting* m_instance;
        if(m_instance == NULL)
        {
            m_instance = new GameSetting;
        }
        return m_instance;
    }
};

#endif // GAMESETTING_H

