//=================================================
// GENERATED FILE, DON'T CHANGE MANUALLY
// To modify, adapt and run the XercesCodeGenerator
//=================================================
#pragma once

#include <xercesc/util/xercesdefs.hpp>
#include <memory>
#include <vector>

#include "XmlClass.h"

// Includes for children

namespace ww2019
{


class XmlDag;


class XmlWeek : public XmlClass
{
public:
    enum class strategie
    {
        KCal,
        Koolhydraten
    };

    XmlWeek();
    ~XmlWeek() override;

    const std::vector<std::unique_ptr<XmlDag>> & GetDagList() const;
    void Add(std::unique_ptr<XmlDag> aDag);
    std::wstring Getbegindatum() const;
    std::wstring Geteinddatum() const;
    int Getpunten() const;
    int Getweekpunten() const;
    std::wstring Getstartweight() const;
    strategie Getstrategie() const;
    void Setbegindatum(const std::wstring & abegindatum);
    void Seteinddatum(const std::wstring & aeinddatum);
    void Setpunten(int apunten);
    void Setweekpunten(int aweekpunten);
    void Setstartweight(const std::wstring & astartweight);
    void Setstrategie(strategie astrategie);

private:
    XmlWeek(const XmlWeek& anOriginal) = delete;
    XmlWeek& operator=(const XmlWeek& anOriginal) = delete;

    std::vector<std::unique_ptr<XmlDag>> mDagList;
    std::wstring mbegindatum;
    std::wstring meinddatum;
    int mpunten;
    int mweekpunten;
    std::wstring mstartweight;
    strategie mstrategie;
};


}
