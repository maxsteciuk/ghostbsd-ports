# Created by: Simun Mikecin <numisemis@yahoo.com>
# $FreeBSD$

PORTNAME=	mongo-cxx-driver
PORTVERSION=	1.1.2
DISTVERSIONPREFIX=legacy-
PORTREVISION=	14
CATEGORIES=	devel

MAINTAINER=	numisemis@yahoo.com
COMMENT=	MongoDB Legacy C++ Driver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/APACHE-2.0.txt

BROKEN_SSL=	openssl
BROKEN_SSL_REASON_openssl=	use of undeclared identifier 'BIO_s_file_internal'

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		SCRAM-SHA-1
OPTIONS_DEFAULT=	SCRAM-SHA-1

SCRAM-SHA-1_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SCRAM-SHA-1_MAKE_ARGS=		--use-sasl-client --ssl
SCRAM-SHA-1_DESC=	SCRAM-SHA-1 authentication mechanism support.

USE_GITHUB=	yes
GH_ACCOUNT=	mongodb
GH_PROJECT=	mongo-cxx-driver

USES=		compiler:c++11-lang scons ssl
MAKE_ARGS=	--prefix=${STAGEDIR}${PREFIX} \
		--cc=${CC} \
		--cxx=${CXX}
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	use of undeclared identifier 'BIO_s_file_internal'
BROKEN_FreeBSD_13=	use of undeclared identifier 'BIO_s_file_internal'
.endif

.include <bsd.port.post.mk>
