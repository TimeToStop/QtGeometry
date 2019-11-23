#ifndef DOUBLE_H
#define DOUBLE_H

class Double
{
    static const double m_diff;
    long double m_x;

public:
    Double(): m_x(0) {}
    template <typename T> Double(T x) : m_x(x) {}
    Double(const Double& other) : m_x(other.m_x) {}

    Double& operator= (const Double& other)
    {
        m_x = other.m_x;
        return *this;
    }

    template <typename T>
    Double& operator= (T x)
    {
        m_x = x;
        return *this;
    }

    template<typename T>
    operator T()
    {
        return static_cast<T>(m_x);
    }

    bool operator==(const Double& other) const
    {
        return (abs(other.m_x - m_x) <= m_diff);
    }

    bool operator!=(const Double& other) const
    {
        return !(*this == other);
    }

    bool operator>(const Double& other) const
    {
        return m_x > other.m_x;
    }

    bool operator<(const Double& other) const
    {
        return m_x < other.m_x;
    }

    bool operator>=(const Double& other) const
    {
        return m_x > other.m_x;
    }

    bool operator<=(const Double& other) const
    {
        return m_x < other.m_x;
    }

    template<typename T>
    bool operator==(T x) const
    {
        return (abs(x - m_x) <= m_diff);
    }

    template<typename T>
    bool operator!=(T other) const
    {
        return !(*this == other);
    }

    template<typename T>
    bool operator>(T x) const
    {
        return m_x > x;
    }

    template<typename T>
    bool operator<(T x) const
    {
        return m_x < x;
    }

    template<typename T>
    bool operator>=(T x) const
    {
        return m_x > x;
    }

    template<typename T>
    bool operator<=(T x) const
    {
        return m_x < x;
    }

    Double operator++()
    {
        m_x++;
        return *this;
    }

    Double operator--()
    {
        m_x--;
        return *this;
    }

    Double operator+()
    {
        return *this;
    }

    Double operator-() const
    {
        return Double(-m_x);
    }

    Double operator+(const Double& other) const
    {
        return (m_x + other.m_x);
    }

    Double operator-(const Double& other) const
    {
        return (m_x - other.m_x);
    }

    Double operator*(const Double& other) const
    {
        return (m_x * other.m_x);
    }

    Double operator/(const Double& other) const
    {
        return (m_x / other.m_x);
    }

    template <typename T>
    Double operator+(T x) const
    {
        return (m_x + x);
    }

    template <typename T>
    Double operator-(T x) const
    {
        return (m_x - x);
    }

    template <typename T>
    Double operator*(T x) const
    {
        return (m_x * x);
    }

    template <typename T>
    Double operator/(T x) const
    {
        return (m_x / x);
    }
    inline Double abs() const
    {
        return (m_x >= 0) ? m_x : -m_x;
    }

    inline static Double abs(const Double& x)
    {
        return (x.m_x >= 0) ? x.m_x : -x.m_x;
    }

private:

    inline static long double abs(long double x)
    {
        return (x >= 0) ? x : -x;
    }
};

#endif // DOUBLE_H
