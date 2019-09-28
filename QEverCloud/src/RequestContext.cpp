#include <RequestContext.h>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class Q_DECL_HIDDEN RequestContext Q_DECL_FINAL: public IRequestContext
{
public:
    RequestContext(QString authenticationToken, quint64 requestTimeout,
                   bool increaseRequestTimeoutExponentially,
                   quint64 maxRequestTimeout,
                   quint32 maxRequestRetryCount) :
        m_authenticationToken(std::move(authenticationToken)),
        m_requestTimeout(requestTimeout),
        m_increaseRequestTimeoutExponentially(increaseRequestTimeoutExponentially),
        m_maxRequestTimeout(maxRequestTimeout),
        m_maxRequestRetryCount(maxRequestRetryCount)
    {}

    virtual QString authenticationToken() const Q_DECL_OVERRIDE
    {
        return m_authenticationToken;
    }

    virtual quint64 requestTimeout() const Q_DECL_OVERRIDE
    {
        return m_requestTimeout;
    }

    virtual bool increaseRequestTimeoutExponentially() const Q_DECL_OVERRIDE
    {
        return m_increaseRequestTimeoutExponentially;
    }

    virtual quint64 maxRequestTimeout() const Q_DECL_OVERRIDE
    {
        return m_maxRequestTimeout;
    }

    virtual quint32 maxRequestRetryCount() const Q_DECL_OVERRIDE
    {
        return m_maxRequestRetryCount;
    }

private:
    QString     m_authenticationToken;
    quint64     m_requestTimeout;
    bool        m_increaseRequestTimeoutExponentially;
    quint64     m_maxRequestTimeout;
    quint32     m_maxRequestRetryCount;
};

////////////////////////////////////////////////////////////////////////////////

template <typename T>
void PrintRequestContext(const IRequestContext & ctx, T & strm)
{
    strm << "RequestContext:\n"
        << "    authentication token = " << ctx.authenticationToken() << "\n"
        << "    request timeout = " << ctx.requestTimeout() << "\n"
        << "    increase request timeout exponentially = "
        << (ctx.increaseRequestTimeoutExponentially() ? "yes" : "no") << "\n"
        << "    max request timeout = " << ctx.maxRequestTimeout() << "\n"
        << "    max request retry count = " << ctx.maxRequestRetryCount() << "\n";
}


QTextStream & operator<<(QTextStream & strm, const IRequestContext & ctx)
{
    PrintRequestContext(ctx, strm);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const IRequestContext & ctx)
{
    PrintRequestContext(ctx, dbg);
    return dbg;
}

////////////////////////////////////////////////////////////////////////////////

IRequestContextPtr NewRequestContext(
    QString authenticationToken,
    quint64 requestTimeout,
    bool increaseRequestTimeoutExponentially,
    quint64 maxRequestTimeout,
    quint32 maxRequestRetryCount)
{
    return std::make_shared<RequestContext>(
        std::move(authenticationToken),
        requestTimeout,
        increaseRequestTimeoutExponentially,
        maxRequestTimeout,
        maxRequestRetryCount);
}

} // namespace qevercloud
