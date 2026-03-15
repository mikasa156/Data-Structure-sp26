#include <stdexcept>
class Integer {
    private:
        int value;
    public:
        Integer(int v = 0) :value(v) {}
        
        int get() {
            return value;
        }

        void set(int v) {
            value = v;
        }

        Integer add(Integer other) {
            return Integer(get() + other.get());
        }

        Integer sub(Integer other) {
            return Integer(get() - other.get());
        }

        Integer mul(Integer other) {
            return Integer(get() * other.get());
        }

        Integer divide(Integer other) {
            if (other.get() == 0) {
                throw std::invalid_argument("Divided by zero");
            }
            return Integer(get() / other.get());
        }

        bool equals(Integer other) {
            return get() == other.get();
        }

        bool lessThan(Integer other) {
            return get() < other.get();
        }

        bool greaterThan(Integer other) {
            return get() > other.get();
        }
        
        void addTo(int v) {
            set(get() + v);
        }

        void subTo(int v) {
            set(get() - v);
        }


};