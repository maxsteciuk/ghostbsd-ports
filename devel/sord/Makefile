# Created by: Michael Beer <beerml@sigma6audio.de>
# $FreeBSD$

PORTNAME=	sord
PORTVERSION=	0.16.2
CATEGORIES=	devel
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	beerml@sigma6audio.de
COMMENT=	Sord is a lightweight C library for storing RDF data in memory

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libserd-0.so:devel/serd libpcre.so:devel/pcre

USES=		pkgconfig python:build tar:bzip2 waf

USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsord-0.so.${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sord_validate
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sordi

.include <bsd.port.mk>
