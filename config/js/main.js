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
		blockTwelveColor : $blockTwelveColorPicker.val()
	};

	localStorage.backgroundColor = options.backgroundColor;
	localStorage.blockOneColor = options.blockOneColor;
	localStorage.blockTwoColor = options.blockTwoColor;
	localStorage.blockThreeColor = options.blockThreeColor;
	localStorage.blockFourColor = options.blockFourColor;
	localStorage.blockFiveColor = options.blockFiveColor;
	localStorage.blockSixColor = options.blockSixColor;
	localStorage.blockSevenColor = options.blockSevenColor;
	localStorage.blockEightColor = options.blockEightColor;
	localStorage.blockNineColor = options.blockNineColor;
	localStorage.blockTenColor = options.blockTenColor;
	localStorage.blockElevenColor = options.blockElevenColor;
	localStorage.blockTwelveColor = options.blockTwelveColor;

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

	if (localStorage.backgroundColor) {
		$backgroundColorPicker[0].value = localStorage.backgroundColor;
		$blockOneColorPicker[0].value = localStorage.blockOneColor;
		$blockTwoColorPicker[0].value = localStorage.blockTwoColor;
		$blockThreeColorPicker[0].value = localStorage.blockThreeColor;
		$blockFourColorPicker[0].value = localStorage.blockFourColor;
		$blockFiveColorPicker[0].value = localStorage.blockFiveColor;
		$blockSixColorPicker[0].value = localStorage.blockSixColor;
		$blockSevenColorPicker[0].value = localStorage.blockSevenColor;
		$blockEightColorPicker[0].value = localStorage.blockEightColor;
		$blockNineColorPicker[0].value = localStorage.blockNineColor;
		$blockTenColorPicker[0].value = localStorage.blockTenColor;
		$blockElevenColorPicker[0].value = localStorage.blockElevenColor;
		$blockTwelveColorPicker[0].value = localStorage.blockTwelveColor;
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
