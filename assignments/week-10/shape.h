#include <utility>
#include <vector>
#include <functional>
#include <iostream>
#include <cmath>

using Point_ = std::pair<float, float>;

class Drawable {
public:
    Drawable(Point_ offset = { 0, 0 }, bool visible = true)
        : offset(offset), visible(visible) {
    }

    virtual std::vector<Point_> draw() = 0;

    void set_offset(const Point_& offset) {
        this->offset = offset;
    }
    const Point_& get_offset() const {
        return offset;
    }

    void set_visible(bool visible = true) {
        this->visible = visible;
    }
    bool get_visible() const {
        return visible;
    }

private:
    bool visible;
    Point_ offset;
};

class Fillable {
public:
    Fillable(Point_ size, bool fill = true)
        : size(size), fill(fill) {
    }

    void set_fill(bool fill = true) {
        this->fill = fill;
    }
    bool get_fill() const {
        return fill;
    }

    void set_size(const Point_& size) {
        this->size = size;
    }
    const Point_& get_size() const {
        return size;
    }
private:
    bool fill;
    Point_ size;
};

class Point : public Drawable {
public:
    Point(Point_ offset = { 0, 0 }, bool visible = true)
        : Drawable(offset, visible) {
    }

    std::vector<Point_> draw() {
        std::vector<Point_> points;

        if (get_visible()) {
            points.push_back(get_offset());
        }

        return points;
    }
};

class Rectangle : public Drawable, public Fillable {
public:
    Rectangle(Point_ offset, Point_ size, bool fill = true, bool visible = true)
        : Drawable(offset, visible), Fillable(size, fill) {
    }

    std::vector<Point_> draw() {
        float x{ get_offset().first }, y{ get_offset().second };
        float w{ get_size().first - 1}, h{ get_size().second - 1};

        std::vector<Point_> points;

        if (get_visible()) {
            for (size_t j = y; j <= y + h; j++) {

                if (get_fill() || (j == y || j == y + h)) {
                    for (int i = round(x); i <= round(x + w); i++) {
                        points.push_back({ i, j });
                    }
                } else {
                    points.push_back({ round(x), j });
                    points.push_back({ round(x + w), j });
                }
            }
        }
        return points;
    }
};

class Circle : public Drawable, public Fillable {
public:
    Circle(Point_ offset, size_t size, bool fill = true, bool visible = true)
        : Drawable(offset, visible), Fillable({ size, size }, fill) {
    }

    std::vector<Point_> draw() {
        float x{ get_offset().first }, y{ get_offset().second };
        float r{ get_size().first }, r2{ r * r };

        std::vector<Point_> points;

        if (get_visible()) {
            for (int j = y-r; j <= y+r; j++) {
                float step{ static_cast<float>(sqrt(r2 - (j-y) * (j-y))) };

                if (get_fill() || j == y - r || j == y + r) {
                    for (int i = round(x - step); i <= round(x + step); i++) {
                        points.push_back({ i, j });
                    }
                } else {
                    points.push_back({ round(x - step), j });
                    points.push_back({ round(x + step), j });
                }
            }
        }
        return points;
    }
};

class Triangle : public Drawable, public Fillable {
public:
    Triangle(Point_ offset, Point_ size, bool fill = true, bool visible = true)
        : Drawable(offset, visible), Fillable(size, fill) {
    }

    std::vector<Point_> draw() {
        float x{ get_offset().first }, y{ get_offset().second };
        float w{ get_size().first }, h{ get_size().second };

        std::vector<Point_> points;

        if (get_visible()) {
            for (size_t j = y - h; j <= y; j++) {
                float step { (w / 2.f) * ((j - y + h) / h) };

                if (get_fill() || (j == y - h || j == y)) {
                    for (int i = round(x - step); i <= round(x + step); i++) {
                        points.push_back({ i, j });
                    }
                } else {
                    points.push_back({ round(x - step), j });
                    points.push_back({ round(x + step), j });
                }
            }
        }

        return points;
    }
};

class Canvas {
public:
    Canvas(size_t row, size_t col, char ch = '*')
        : row(row), col(col), ch(ch), matrix(row, std::vector<bool>(col, false)) {
    }
    ~Canvas() {}

    void resize(size_t row, size_t col) {
        row = row;
        col = col;
    }

    size_t add(Point* drawable) {
        drawable_components.push_back(drawable);
        fillable_components.push_back(nullptr);

        return drawable_components.size() - 1;
    }

    template <typename T>
    size_t add(T fillable) {
        drawable_components.push_back(fillable);
        fillable_components.push_back(fillable);

        return drawable_components.size() - 1;
    }

    void draw() {
        matrix = std::vector<std::vector<bool>>(row, std::vector<bool>(col, false));

        for (auto component : drawable_components) {
            for (auto point : component->draw()) {
                if (point.first <= 0 || point.first > col || point.second <= 0 || point.second > row) {
                    continue;
                }
                matrix[round(point.second - 1)][round(point.first - 1)] = true;
            }
        }

        for (size_t y = 0; y < row; y++) {
            for (size_t x = 0; x < col; x++) {
                std::cout << (matrix[y][x] ? ch : '.');
            }
            std::cout << std::endl;
        }
    }

    void drawable_apply(const std::function<void(Drawable*)>& f) {
        for (auto component : drawable_components) {
            f(component);
        }
    }
    void fillable_apply(const std::function<void(Fillable*)>& f) {
        for (auto component : fillable_components) {
            f(component);
        }
    }

    void clear() {
        drawable_components.clear();
        fillable_components.clear();
    }

    void set_ch(char ch) {
        ch = ch;
    }
    char get_ch() const {
        return ch;
    }

    Drawable* at_drawable(size_t index) {
        return drawable_components[index];
    }
    Fillable* at_fillable(size_t index) {
        return fillable_components[index];
    }

private:
    size_t row, col;
    char ch;
    std::vector<Drawable*> drawable_components;
    std::vector<Fillable*> fillable_components;

    std::vector<std::vector<bool>> matrix;
};
