/**
 * Copyright (c) 2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_UTILITY_TO_RANGE_H
#define QEVERCLOUD_UTILITY_TO_RANGE_H

namespace qevercloud {

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

#endif // QEVERCLOUD_UTILITY_TO_RANGE_H
