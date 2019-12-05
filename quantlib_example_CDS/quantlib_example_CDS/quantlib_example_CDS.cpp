#include <iostream>
#include <boost/timer.hpp>
#include <ql/quantlib.hpp>

using namespace QuantLib;
int main()
{
	boost::timer timer;
	Date tradeDate(13, June, 2011);

	Settings::instance().evaluationDate() = tradeDate;

	ext::shared_ptr<DepositRateHelper> dp1m =
		ext::make_shared<DepositRateHelper>(0.00445, 1 * Months, 2,
			WeekendsOnly(), ModifiedFollowing,
			false, Actual360());
	ext::shared_ptr<DepositRateHelper> dp2m =
		ext::make_shared<DepositRateHelper>(0.00949, 2 * Months, 2,
			WeekendsOnly(), ModifiedFollowing,
			false, Actual360());
	ext::shared_ptr<DepositRateHelper> dp3m =
		ext::make_shared<DepositRateHelper>(0.01234, 3 * Months, 2,
			WeekendsOnly(), ModifiedFollowing,
			false, Actual360());
	ext::shared_ptr<DepositRateHelper> dp6m =
		ext::make_shared<DepositRateHelper>(0.01776, 6 * Months, 2,
			WeekendsOnly(), ModifiedFollowing,
			false, Actual360());
	ext::shared_ptr<DepositRateHelper> dp9m =
		ext::make_shared<DepositRateHelper>(0.01935, 9 * Months, 2,
			WeekendsOnly(), ModifiedFollowing,
			false, Actual360());
	ext::shared_ptr<DepositRateHelper> dp1y =
		ext::make_shared<DepositRateHelper>(0.02084, 12 * Months, 2,
			WeekendsOnly(), ModifiedFollowing,
			false, Actual360());

	//// this index is probably not important since we are not using
	//// IborCoupon::usingAtParCoupons() == false 
	//// - define it "isda compliant" anyway
	//ext::shared_ptr<IborIndex> euribor6m = ext::make_shared<IborIndex>(
	//	"IsdaIbor", 6 * Months, 2, EURCurrency(), WeekendsOnly(),
	//	ModifiedFollowing, false, Actual360());

	boost::shared_ptr<QuantLib::IborIndex> euribor6m = boost::make_shared<QuantLib::Euribor6M>();
	std::vector<std::pair<QuantLib::Period, QuantLib::Rate>> swapRates = {
		std::pair<QuantLib::Period, QuantLib::Rate>(QuantLib::Period(2, QuantLib::Years), 0.01652), 
		std::pair<QuantLib::Period, QuantLib::Rate>(QuantLib::Period(3, QuantLib::Years), 0.02018),
		std::pair<QuantLib::Period, QuantLib::Rate>(QuantLib::Period(4, QuantLib::Years), 0.02303),
		std::pair<QuantLib::Period, QuantLib::Rate>(QuantLib::Period(5, QuantLib::Years), 0.02525),
		std::pair<QuantLib::Period, QuantLib::Rate>(QuantLib::Period(6, QuantLib::Years), 0.02696),
		std::pair<QuantLib::Period, QuantLib::Rate>(QuantLib::Period(7, QuantLib::Years), 0.02825),
		std::pair<QuantLib::Period, QuantLib::Rate>(QuantLib::Period(8, QuantLib::Years), 0.02931)
	};

	ext::shared_ptr<SwapRateHelper> sw2y = ext::make_shared<SwapRateHelper>(
		0.01652, 2 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw3y = ext::make_shared<SwapRateHelper>(
		0.02018, 3 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw4y = ext::make_shared<SwapRateHelper>(
		0.02303, 4 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw5y = ext::make_shared<SwapRateHelper>(
		0.02525, 5 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw6y = ext::make_shared<SwapRateHelper>(
		0.02696, 6 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw7y = ext::make_shared<SwapRateHelper>(
		0.02825, 7 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw8y = ext::make_shared<SwapRateHelper>(
		0.02931, 8 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw9y = ext::make_shared<SwapRateHelper>(
		0.03017, 9 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw10y = ext::make_shared<SwapRateHelper>(
		0.03092, 10 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw11y = ext::make_shared<SwapRateHelper>(
		0.03160, 11 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw12y = ext::make_shared<SwapRateHelper>(
		0.03231, 12 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw15y = ext::make_shared<SwapRateHelper>(
		0.03367, 15 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw20y = ext::make_shared<SwapRateHelper>(
		0.03419, 20 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw25y = ext::make_shared<SwapRateHelper>(
		0.03411, 25 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);
	ext::shared_ptr<SwapRateHelper> sw30y = ext::make_shared<SwapRateHelper>(
		0.03412, 30 * Years, WeekendsOnly(), Annual, ModifiedFollowing, Thirty360(),
		euribor6m);

	std::vector<ext::shared_ptr<RateHelper> > isdaYieldHelpers;

	isdaYieldHelpers.push_back(dp1m);
	isdaYieldHelpers.push_back(dp2m);
	isdaYieldHelpers.push_back(dp3m);
	isdaYieldHelpers.push_back(dp6m);
	isdaYieldHelpers.push_back(dp9m);
	isdaYieldHelpers.push_back(dp1y);
	isdaYieldHelpers.push_back(sw2y);
	isdaYieldHelpers.push_back(sw3y);
	isdaYieldHelpers.push_back(sw4y);
	isdaYieldHelpers.push_back(sw5y);
	isdaYieldHelpers.push_back(sw6y);
	isdaYieldHelpers.push_back(sw7y);
	isdaYieldHelpers.push_back(sw8y);
	isdaYieldHelpers.push_back(sw9y);
	isdaYieldHelpers.push_back(sw10y);
	isdaYieldHelpers.push_back(sw11y);
	isdaYieldHelpers.push_back(sw12y);
	isdaYieldHelpers.push_back(sw15y);
	isdaYieldHelpers.push_back(sw20y);
	isdaYieldHelpers.push_back(sw25y);
	isdaYieldHelpers.push_back(sw30y);

	// build yield curve
	Handle<YieldTermStructure> isdaYts = Handle<YieldTermStructure>(
		ext::make_shared<PiecewiseYieldCurve<Discount, LogLinear> >(
			0, WeekendsOnly(), isdaYieldHelpers, Actual365Fixed()));
	isdaYts->enableExtrapolation();


	CreditDefaultSwap::PricingModel model = CreditDefaultSwap::ISDA;
	ext::shared_ptr<CdsHelper> cds6m(new SpreadCdsHelper(
		0.007927, 6 * Months, 1, WeekendsOnly(), Quarterly, Following,
		DateGeneration::CDS, Actual360(), 0.4, isdaYts, true, true, Date(),
		Actual360(true), true, model));
	ext::shared_ptr<CdsHelper> cds1y(new SpreadCdsHelper(
		0.007927, 1 * Years, 1, WeekendsOnly(), Quarterly, Following,
		DateGeneration::CDS, Actual360(), 0.4, isdaYts, true, true, Date(),
		Actual360(true), true, model));
	ext::shared_ptr<CdsHelper> cds3y(new SpreadCdsHelper(
		0.012239, 3 * Years, 1, WeekendsOnly(), Quarterly, Following,
		DateGeneration::CDS, Actual360(), 0.4, isdaYts, true, true, Date(),
		Actual360(true), true, model));
	ext::shared_ptr<CdsHelper> cds5y(new SpreadCdsHelper(
		0.016979, 5 * Years, 1, WeekendsOnly(), Quarterly, Following,
		DateGeneration::CDS, Actual360(), 0.4, isdaYts, true, true, Date(),
		Actual360(true), true, model));
	ext::shared_ptr<CdsHelper> cds7y(new SpreadCdsHelper(
		0.019271, 7 * Years, 1, WeekendsOnly(), Quarterly, Following,
		DateGeneration::CDS, Actual360(), 0.4, isdaYts, true, true, Date(),
		Actual360(true), true, model));
	ext::shared_ptr<CdsHelper> cds10y(new SpreadCdsHelper(
		0.020860, 10 * Years, 1, WeekendsOnly(), Quarterly, Following,
		DateGeneration::CDS, Actual360(), 0.4, isdaYts, true, true, Date(),
		Actual360(true), true, model));

	std::vector<ext::shared_ptr<DefaultProbabilityHelper> > isdaCdsHelpers;

	isdaCdsHelpers.push_back(cds6m);
	isdaCdsHelpers.push_back(cds1y);
	isdaCdsHelpers.push_back(cds3y);
	isdaCdsHelpers.push_back(cds5y);
	isdaCdsHelpers.push_back(cds7y);
	isdaCdsHelpers.push_back(cds10y);

	// build credit curve
	Handle<DefaultProbabilityTermStructure> isdaCts =
		Handle<DefaultProbabilityTermStructure>(ext::make_shared<
			PiecewiseDefaultCurve<SurvivalProbability, LogLinear> >(
				0, WeekendsOnly(), isdaCdsHelpers, Actual365Fixed()));

	//// set up isda engine
	//ext::shared_ptr<IsdaCdsEngine> isdaPricer =
	//	ext::make_shared<IsdaCdsEngine>(
	//		isdaCts, 0.4, isdaYts);

	// check the curves
	std::cout << "ISDA yield curve:" << std::endl;
	std::cout << "date;time;zeroyield" << std::endl;
	for (Size i = 0; i < isdaYieldHelpers.size(); i++) {
		Date d = isdaYieldHelpers[i]->latestDate();
		Real t = isdaYts->timeFromReference(d);
		std::cout << d << ";" << t << ";"
			<< isdaYts->zeroRate(d, Actual365Fixed(), Continuous).rate()
			<< std::endl;
	}

	std::cout << "ISDA credit curve:" << std::endl;
	std::cout << "date;time;survivalprob" << std::endl;
	for (Size i = 0; i < isdaCdsHelpers.size(); i++) {
		Date d = isdaCdsHelpers[i]->latestDate();
		Real t = isdaCts->timeFromReference(d);
		std::cout << d << ";" << t << ";" << isdaCts->survivalProbability(d)
			<< std::endl;
	}


	std::cout << "Computation time: " << timer.elapsed() << std::endl;;
	return 0;
}
