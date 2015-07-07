/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point tmp;

    tmp.x = x;
    tmp.y = y;
    return tmp;
}

/* addpoint: add two points */
struct addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}

int main(void) {
    return 0;
}
