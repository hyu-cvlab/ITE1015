#include <utility>
#include <vector>

using Point_ = std::pair<int, int>;

class Drawable {
public:
    Drawable(Point_ center = {0, 0}, bool visible = true)
    : center(center), visible(visible) {
    }

    virtual std::vector<Point_> draw() = 0;

    void set_center(const Point_& center) {
        this->center = center;
    }
    const Point_& get_center() const {
        return center;
    }

    void set_visible(bool visible = true) {
        this->visible = visible;
    }
    bool get_visible() const {
        return visible;
    }

private:
    bool visible;
    Point_ center;
};

class Fillable {
public:
    Fillable(bool fill = true)
    : fill(fill) {
    }

    void set_fill(bool fill = true) {
        this->fill = fill;
    }
    bool get_fill() const {
        return fill;
    }
private:
    bool fill;
};

class Point : public Drawable {
public:
    Point(Point_ center = {0, 0}, bool visible = true)
    : Drawable(center, visible) {
    }

    std::vector<Point_> draw() {
        return {get_center()};
    }
};

class Rectangle : public Drawable, public Fillable {
public:
    Rectangle(Point_ center, Point_ size, bool fill = true, bool visible = true)
    : Drawable(center, visible), size(size): Fillable(fill) {
    }

    void set_size(const Point_& size) {
        this->size = size;
    }
    const Point_& get_size(const Point_& size) const {
        return size;
    }

private:
    Point_ size;
}

class Circle : public Drawable, public Fillable {
public:
    Rectangle(Point_ center, size_t size, bool fill = true, bool visible = true)
    : Drawable(center, visible), size(size): Fillable(fill) {
    }

    void set_size(size_t size) {
        this->size = size;
    }
    size_t get_size(size_t size) const {
        return size;
    }

private:
    size_t size;
}

class Triangle : public Drawable, public Fillable {
public:
    Rectangle(Point_ center, size_t size, bool fill = true, bool visible = true)
    : Drawable(center, visible), size(size): Fillable(fill) {
    }

    void set_size(size_t size) {
        this->size = size;
    }
    size_t get_size(size_t size) const {
        return size;
    }

private:
    size_t size;
}

class Canvas {
public:
    Canvas(size_t row, size_t col);
    ~Canvas();

    void resize(size_t row, size_t col);

    void add(const Drawable& component);
    bool draw();
    void show();
};
