#include "requestmapper.h"

#include <QLoggingCategory>
Q_LOGGING_CATEGORY(RequestMapperCat, "RequestMapper")

RequestMapper::RequestMapper(QObject* parent)
    : HttpRequestHandler(parent)
{
}

RequestMapper::~RequestMapper(){
}

void RequestMapper::service(HttpRequest &request, HttpResponse &response){
    QString path(request.getPath());
    qCDebug(RequestMapperCat) << "path" << path;

    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");

    response.write( "<html>"
                        "<body>"
                            "Hello World!"
                        "</body>"
                    "</html>");
}

