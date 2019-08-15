/**
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef QEVERCLOUD_GENERATOR_THRIFT_HELPERS_H
#define QEVERCLOUD_GENERATOR_THRIFT_HELPERS_H

#include <QtGlobal>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

#if QT_VERSION < QT_VERSION_CHECK(5, 7, 0)

// this adds const to non-const objects (like std::as_const)
template <typename T>
Q_DECL_CONSTEXPR
typename std::add_const<T>::type & qAsConst(T & t) Q_DECL_NOTHROW
{
    return t;
}

// prevent rvalue arguments:
template <typename T>
void qAsConst(const T &&) Q_DECL_EQ_DELETE;

#endif // QT_VERSION_CHECK

////////////////////////////////////////////////////////////////////////////////

template <typename Container>
class QAssociativeContainerReferenceWrapper
{
public:
    struct iterator
    {
        typename Container::iterator m_iterator;
        iterator(const typename Container::iterator it) :
            m_iterator(it)
        {}

        typename Container::iterator operator*()
        {
            return m_iterator;
        }

        iterator & operator++()
        {
            ++m_iterator;
            return *this;
        }

        bool operator!=(const iterator & other) const
        {
            return m_iterator != other.m_iterator;
        }
    };

public:
    QAssociativeContainerReferenceWrapper(Container & container)
        : m_container(container)
    {}

    iterator begin() {
        return m_container.begin();
    }

    iterator end() {
        return m_container.end();
    }

private:
    Container & m_container;
};

////////////////////////////////////////////////////////////////////////////////

template <typename Container>
class QAssociativeContainerConstReferenceWrapper
{
public:
    struct iterator
    {
        typename Container::const_iterator m_iterator;
        iterator(const typename Container::const_iterator it) :
            m_iterator(it)
        {}

        typename Container::const_iterator operator*()
        {
            return m_iterator;
        }

        iterator & operator++()
        {
            ++m_iterator;
            return *this;
        }

        bool operator!=(const iterator & other) const
        {
            return m_iterator != other.m_iterator;
        }
    };

public:
    QAssociativeContainerConstReferenceWrapper(const Container & container)
        : m_container(container)
    {}

    iterator begin() const {
        return m_container.begin();
    }

    iterator end() const {
        return m_container.end();
    }

private:
    const Container & m_container;
};

////////////////////////////////////////////////////////////////////////////////

template <class Container>
QAssociativeContainerReferenceWrapper<Container> toRange(Container & container)
{
    return QAssociativeContainerReferenceWrapper<Container>(container);
}

////////////////////////////////////////////////////////////////////////////////

template <class Container>
QAssociativeContainerConstReferenceWrapper<Container> toRange(
    const Container & container)
{
    return QAssociativeContainerConstReferenceWrapper<Container>(container);
}

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATOR_THRIFT_HELPERS_H
