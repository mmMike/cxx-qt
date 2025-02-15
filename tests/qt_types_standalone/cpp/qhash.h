// clang-format off
// SPDX-FileCopyrightText: 2022 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>
// clang-format on
// SPDX-FileContributor: Andrew Hayzen <andrew.hayzen@kdab.com>
//
// SPDX-License-Identifier: MIT OR Apache-2.0
#pragma once

#include <QtCore/QHash>
#include <QtCore/QVariant>
#include <QtTest/QTest>

#include "cxx-qt-gen/qhash_cxx.cxx.h"

class QHashTest : public QObject
{
  Q_OBJECT

private Q_SLOTS:
  void construct()
  {
    const auto h = construct_qhash_qstring_qvariant();
    QVERIFY(h.contains(QStringLiteral("kdab")));
    QCOMPARE(h.value(QStringLiteral("kdab")), 10);
    QVERIFY(h.contains(QStringLiteral("Qt")));
    QCOMPARE(h.value(QStringLiteral("Qt")), QStringLiteral("Rust"));
    QVERIFY(!h.contains(QStringLiteral("github")));
    QCOMPARE(h.size(), 2);
  }

  void read()
  {
    auto h = QVariantHash();
    h.insert(QStringLiteral("kdab"), 10);
    h.insert(QStringLiteral("Qt"), QStringLiteral("Rust"));
    QVERIFY(read_qhash_qstring_qvariant(h));
  }

  void clone()
  {
    auto h = QVariantHash();
    h.insert(QStringLiteral("kdab"), 10);
    h.insert(QStringLiteral("Qt"), QStringLiteral("Rust"));
    const auto c = clone_qhash_qstring_qvariant(h);
    QVERIFY(c.contains(QStringLiteral("kdab")));
    QCOMPARE(c.value(QStringLiteral("kdab")), 10);
    QVERIFY(c.contains(QStringLiteral("Qt")));
    QCOMPARE(c.value(QStringLiteral("Qt")), QStringLiteral("Rust"));
    QVERIFY(!c.contains(QStringLiteral("github")));
    QCOMPARE(c.size(), 2);
  }
};
