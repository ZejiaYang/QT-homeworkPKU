#include "map.h"

Map::Map()
{
    m_map1.load("://parkour_resource/map1.png");
    m_map2.load("://parkour_resource/map2.png");

    m_map1_posX = 0;
    m_map2_posX = GAME_WIDTH;

    m_scroll_speed = MAP_SCROLL_SPEED;
}

void Map::mapPosition(){
    m_map1_posX -= m_scroll_speed;
    m_map2_posX -= m_scroll_speed;
    if(m_map1_posX<=-GAME_WIDTH){
        m_map1_posX = 0;
    }
    if(m_map2_posX<=0 ){
        m_map2_posX = GAME_WIDTH;
    }
}
