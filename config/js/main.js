(function() {
	loadOptions();
	submitHandler();
})();

function submitHandler() {
	var $submitButton = $('#submitButton');
	$submitButton.on('click', function() {
		console.log('Submit');

		var return_to = getQueryParam('return_to', 'pebblejs://close#');
		document.location = return_to + encodeURIComponent(JSON.stringify(getAndStoreConfigData()));
	});
}

var $submitButton = $('#submitButton');

$submitButton.on('click', function() {
	console.log('Submit');

	var return_to = getQueryParam('return_to', 'pebblejs://close#');
	document.location = return_to + encodeURIComponent(JSON.stringify(getAndStoreConfigData()));
});

var degreeOption = 0;
function tabClickHandler(value) {
	console.log(value);
	if (value == "Celsius") {
		degreeOption = 0;
	} else if (value == "Fahrenheit") {
		degreeOption = 1;
	}
}

function getAndStoreConfigData() {
	var $backgroundColorPicker = $('#backgroundColorPicker');
	var $blockOneColorPicker = $('#blockOneColorPicker');
	var $blockTwoColorPicker = $('#blockTwoColorPicker');
	var $blockThreeColorPicker = $('#blockThreeColorPicker');
	var $blockFourColorPicker = $('#blockFourColorPicker');
	var $blockFiveColorPicker = $('#blockFiveColorPicker');
	var $blockSixColorPicker = $('#blockSixColorPicker');
	var $blockSevenColorPicker = $('#blockSevenColorPicker');
	var $blockEightColorPicker = $('#blockEightColorPicker');
	var $blockNineColorPicker = $('#blockNineColorPicker');
	var $blockTenColorPicker = $('#blockTenColorPicker');
	var $blockElevenColorPicker = $('#blockElevenColorPicker');
	var $blockTwelveColorPicker = $('#blockTwelveColorPicker');

	var options = {
		backgroundColor : $backgroundColorPicker.val(),
		blockOneColor : $blockOneColorPicker.val(),
		blockTwoColor : $blockTwoColorPicker.val(),
		blockThreeColor : $blockThreeColorPicker.val(),
		blockFourColor : $blockFourColorPicker.val(),
		blockFiveColor : $blockFiveColorPicker.val(),
		blockSixColor : $blockSixColorPicker.val(),
		blockSevenColor : $blockSevenColorPicker.val(),
		blockEightColor : $blockEightColorPicker.val(),
		blockNineColor : $blockNineColorPicker.val(),
		blockTenColor : $blockTenColorPicker.val(),
		blockElevenColor : $blockElevenColorPicker.val(),
		blockTwelveColor : $blockTwelveColorPicker.val(),
		degreeOption : degreeOption
	};

	localStorage.willdorfblockybackgroundColor = options.backgroundColor;
	localStorage.willdorfblockyblockOneColor = options.blockOneColor;
	localStorage.willdorfblockyblockTwoColor = options.blockTwoColor;
	localStorage.willdorfblockyblockThreeColor = options.blockThreeColor;
	localStorage.willdorfblockyblockFourColor = options.blockFourColor;
	localStorage.willdorfblockyblockFiveColor = options.blockFiveColor;
	localStorage.willdorfblockyblockSixColor = options.blockSixColor;
	localStorage.willdorfblockyblockSevenColor = options.blockSevenColor;
	localStorage.willdorfblockyblockEightColor = options.blockEightColor;
	localStorage.willdorfblockyblockNineColor = options.blockNineColor;
	localStorage.willdorfblockyblockTenColor = options.blockTenColor;
	localStorage.willdorfblockyblockElevenColor = options.blockElevenColor;
	localStorage.willdorfblockyblockTwelveColor = options.blockTwelveColor;
	localStorage.willdorfblockydegreeOption = options.degreeOption;

	console.log('Got Options: ' + JSON.stringify(options));
	return options;
}

function loadOptions() {
	var $backgroundColorPicker = $('#backgroundColorPicker');
	var $blockOneColorPicker = $('#blockOneColorPicker');
	var $blockTwoColorPicker = $('#blockTwoColorPicker');
	var $blockThreeColorPicker = $('#blockThreeColorPicker');
	var $blockFourColorPicker = $('#blockFourColorPicker');
	var $blockFiveColorPicker = $('#blockFiveColorPicker');
	var $blockSixColorPicker = $('#blockSixColorPicker');
	var $blockSevenColorPicker = $('#blockSevenColorPicker');
	var $blockEightColorPicker = $('#blockEightColorPicker');
	var $blockNineColorPicker = $('#blockNineColorPicker');
	var $blockTenColorPicker = $('#blockTenColorPicker');
	var $blockElevenColorPicker = $('#blockElevenColorPicker');
	var $blockTwelveColorPicker = $('#blockTwelveColorPicker');

	if (localStorage.willdorfblockybackgroundColor) {
		$backgroundColorPicker[0].value = localStorage.willdorfblockybackgroundColor;
		$blockOneColorPicker[0].value = localStorage.willdorfblockyblockOneColor;
		$blockTwoColorPicker[0].value = localStorage.willdorfblockyblockTwoColor;
		$blockThreeColorPicker[0].value = localStorage.willdorfblockyblockThreeColor;
		$blockFourColorPicker[0].value = localStorage.willdorfblockyblockFourColor;
		$blockFiveColorPicker[0].value = localStorage.willdorfblockyblockFiveColor;
		$blockSixColorPicker[0].value = localStorage.willdorfblockyblockSixColor;
		$blockSevenColorPicker[0].value = localStorage.willdorfblockyblockSevenColor;
		$blockEightColorPicker[0].value = localStorage.willdorfblockyblockEightColor;
		$blockNineColorPicker[0].value = localStorage.willdorfblockyblockNineColor;
		$blockTenColorPicker[0].value = localStorage.willdorfblockyblockTenColor;
		$blockElevenColorPicker[0].value = localStorage.willdorfblockyblockElevenColor;
		$blockTwelveColorPicker[0].value = localStorage.willdorfblockyblockTwelveColor;

		//set the corresponding tab to active
		degreeOption = localStorage.willdorfblockydegreeOption;
		if (degreeOption == 0) {
			$('#Celsius').attr('class', 'tab-button active');
		} else {
			$('#Fahrenheit').attr('class', 'tab-button active');
		}
	} else {
		$('#Celsius').attr('class', 'tab-button active');
	}
}

function getQueryParam(variable, defaultValue) {
	var query = location.search.substring(1);
	var vars = query.split('&');
	for (var i = 0; i < vars.length; i++) {
		var pair = vars[i].split('=');
		if (pair[0] === variable) {
			return decodeURIComponent(pair[1]);
		}
	}
	return defaultValue || false;
}
