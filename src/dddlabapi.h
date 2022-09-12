/**
 *  Copyright (c) 2022 Canlab s.r.o
 *
 */
#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <curl/curl.h>

namespace dddlabapi
{
    std::pair<long, std::string> uploadFile(std::string jwt_token, std::string filepath);
    std::pair<long, std::string> uploadFileV2(std::string jwt_token, std::string filepath);

    std::pair<long, std::string> getAnalysisPreview(std::string jwt_token, std::string filename);
    std::pair<long, std::string> getAnalysis(std::string jwt_token, std::string filename, std::string card_id, std::string period_begin, std::string period_end, bool summ_daily=true, bool summ_weekly=true, bool summ_monthly=true, bool workshifts=true, bool rests=true, bool activities=true);
   
    std::pair<long, std::string> getHTML(std::string jwt_token,std::string filename, std::string local);
    std::pair<long, std::string> getHTMLV2(std::string jwt_token, std::string filename, std::string local);

}