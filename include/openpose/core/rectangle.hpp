#ifndef OPENPOSE_CORE_RECTANGLE_HPP
#define OPENPOSE_CORE_RECTANGLE_HPP

#include "point.hpp"

namespace op
{
    template<typename T>
    struct Rectangle
    {
        T x;
        T y;
        T width;
        T height;

        Rectangle(const T x = 0, const T y = 0, const T width = 0, const T height = 0);

        /**
         * Copy constructor.
         * It performs `fast copy`: For performance purpose, copying a Rectangle<T> or Datum or cv::Mat just copies the reference, it still shares the same internal data.
         * Modifying the copied element will modify the original one.
         * Use clone() for a slower but real copy, similarly to cv::Mat and Rectangle<T>.
         * @param rectangle Rectangle to be copied.
         */
        Rectangle<T>(const Rectangle<T>& rectangle);

        /**
         * Copy assignment.
         * Similar to Rectangle<T>(const Rectangle<T>& rectangle).
         * @param rectangle Rectangle to be copied.
         * @return The resulting Rectangle.
         */
        Rectangle<T>& operator=(const Rectangle<T>& rectangle);

        /**
         * Move constructor.
         * It destroys the original Rectangle to be moved.
         * @param rectangle Rectangle to be moved.
         */
        Rectangle<T>(Rectangle<T>&& rectangle);

        /**
         * Move assignment.
         * Similar to Rectangle<T>(Rectangle<T>&& rectangle).
         * @param rectangle Rectangle to be moved.
         * @return The resulting Rectangle.
         */
        Rectangle<T>& operator=(Rectangle<T>&& rectangle);

        Point<T> center() const;

        inline Point<T> topLeft() const
        {
            return Point<T>{x, y};
        }

        Point<T> bottomRight() const;

        inline T area() const
        {
            return width * height;
        }

        // -------------------------------------------------- Basic Operators -------------------------------------------------- //
        Rectangle<T>& operator*=(const T value);

        Rectangle<T> operator*(const T value) const;

        Rectangle<T>& operator/=(const T value);

        Rectangle<T> operator/(const T value) const;
    };
}

#endif // OPENPOSE_CORE_RECTANGLE_HPP
