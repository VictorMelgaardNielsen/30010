#include "variabel.h"

void gravityCheckBullet(bullet_t *b, meteor_t m) {

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
        b.x = -1;
        b.y = -1;
    }

}

void gravityCheckShip(ship_t *ship, meteor_t m) {

    if (ship->x < m.x && ship->x > m.x - 4 && ship->y < m.y && ship->y > m.y - 2) {
        ship->vx += 1;
        ship->vy += 1;
    }

    if (ship->x >= m.x && ship->x <= m.x + 10 && ship->y < m.y && ship->y > m.y - 2) {
        ship->vy += 1;
    }

    if (ship->x > m.x + 10 && ship->x < m.x + 14 && ship->y < m.y && ship->y > m.y - 2) {
        ship->vx += -1;
        ship->vy += 1;
    }

    if (ship->x < m.x && ship->x > m.x - 4 && ship->y >= m.y && ship->y <= m.y + 4) {
        ship->vx += 1;
    }

    if (ship->x < m.x && ship->x > m.x - 4 && ship->y > m.y + 4 && ship->y < m.y + 6) {
        ship->vx += 1;
        ship->vy += -1;
    }

    if (ship->x >= m.x && ship->x <= m.x + 10 && ship->y > m.y + 4 && ship->y < m.y + 6) {
        ship->vy += -1;
    }

    if (ship->x > m.x + 10 && ship->x < m.x + 14 && ship->y > m.y + 4 && ship->y < m.y + 6) {
        ship->vx += -1;
        ship->vy += -1;
    }

    if (ship->x > m.x + 10 && ship->x < m.x + 14 && ship->y >= m.y && ship->y <= m.y + 4) {
        ship->vx += -1;
    }

    if (ship>x >= m.x && ship->x <= m.x + 10 && ship->y >= m.y && ship->y <= m.y + 4) {
        ship->healthpoints = 0;
    }

}

/*

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







