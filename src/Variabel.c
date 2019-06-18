#include "variabel.h"

void coordinatRandomiser(uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2, meteor_t *m) {
    m->x = (rand() % (x2-x1)) + x1;
    m->y = (rand() % (y2-y1)) + y1;

}

/*
void gravityCheck(bullet_t *b, meteor_t *m) {

    if (b.x < m.x && b.x > m.x - 4 && b.y < m.y && b.y > m.y - 2) {
        b.vx += 1;
        b.vy += 1;
    }

    if (b.x >= m.x && b.x <= m.x + 10 && b.y < m.y && b.y > m.y - 2) {
        b.vy += 1;
    }

    if (b.x > m.x + 10 && b.x < m.x + 14 && b.y < m.y && b.y > m.y - 2) {
        b.vx += -1;
        b.vy += 1;
    }

    if (b.x < m.x && b.x > m.x - 4 && b.y >= m.y && b.y <= m.y + 4) {
        b.vx += 1;
    }

    if (b.x < m.x && b.x > m.x - 4 && b.y > m.y + 4 && b.y < m.y + 6) {
        b.vx += 1;
        b.vy += -1;
    }

    if (b.x >= m.x && b.x <= m.x + 10 && b.y > m.y + 4 && b.y < m.y + 6) {
        b.vy += -1;
    }

    if (b.x > m.x + 10 && b.x < m.x + 14 && b.y > m.y + 4 && b.y < m.y + 6) {
        b.vx += -1;
        b.vy += -1;
    }

    if (b.x > m.x + 10 && b.x < m.x + 14 && b.y >= m.y && b.y <= m.y + 4) {
        b.vx += -1;
    }

    if (b.x >= m.x && b.x <= m.x + 10 && b.y >= m.y && b.y <= m.y + 4) {
        b.vx = 0;
        b.vy = 0;
    }

}

void powerUp_Nuke (spaceship_t x) {
    counter_t nuke = 0;

    if (x.x == n.x && x.y == n.y) {
        nuke++;
    }

}

void use_Nuke(int8_t a) {
    if (n == 1) {
    enemyship_t e;
    e.life--;
    }
}

void update_Bullets(spaceship_t x) {
    if (x.x == laser.x && x.y == laser.y) {
        bullets.style = 2;
    }

    if ()

}

*/







