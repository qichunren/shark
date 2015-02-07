//
// Copyright 2010-2015 Jacob Dawid <jacob@omg-it.works>
//
// This file is part of QtWebServer.
//
// QtWebServer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// QtWebServer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with QtWebServer.  If not, see <http://www.gnu.org/licenses/>.
//

#pragma once

// Own includes
#include "statuscodes.h"
#include "logger.h"

// Qt includes
#include <QByteArray>

namespace WebServer {

/**
 * @brief The Response class
 * @author Jacob Dawid
 * @date 23.11.2013
 */
class NetworkResponse : public Logger {
public:
    /**
     * @brief The CharacterEncoding enum
     */
    enum CharacterEncoding {
        Utf8
    };

    /**
     * @brief Constructor.
     */
    NetworkResponse();

    /**
     * @brief Converts the response into a byte array. The resulting character
     * encoding is determined by the characterEncoding attribute.
     * @returns The resulting byte array.
     */
    QByteArray toByteArray();

    /**
     * @returns The status code of this response.
     */
    Http::StatusCode statusCode();

    /**
     * @brief Sets the status code for this response. The reason phrase will be
     * added automatically.
     * @param statusCode A HTTP status code.
     */
    void setStatusCode(Http::StatusCode statusCode);

    /**
     * @returns The content type of this response.
     */
    QString contentType();

    /**
     * @brief Sets the specified content type.
     * @param contentType A content type string.
     */
    void setContentType(QString contentType);

    /**
     * @returns The character encoding of this response.
     */
    CharacterEncoding characterEncoding();

    /**
     * @brief Sets the character encoding for this response.
     * @param characterEncoding A character encoding.
     */
    void setCharacterEncoding(CharacterEncoding characterEncoding);

    /**
     * @returns The response body part.
     */
    QString body();

    /**
     * @brief Sets the response body, ie. the actual document transmitted.
     * @param body An HTTP response body.
     */
    void setBody(QString body);

private:
    Http::StatusCode    _statusCode;
    QString             _contentType;
    CharacterEncoding   _characterEncoding;
    QString             _body;
};

} // namespace WebServer