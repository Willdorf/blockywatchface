Pebble.addEventListener('ready', function() {
	console.log('PebbleKit JS ready!');
});

Pebble.addEventListener('showConfiguration', function() {
	var url = 'http://armstrongwill.com/pebbleconfigurationpages/blocky/index.html';

	console.log('Showing configuration page: ' + url);

	Pebble.openURL(url);
});

Pebble.addEventListener('webviewclosed', function(e) {
	var configData = JSON.parse(decodeURIComponent(e.response));

	console.log('Configuration page returned: ' + JSON.stringify(configData));

	if (configData.backgroundColor) {
		Pebble.sendAppMessage({
			backgroundColor : parseInt(configData.backgroundColor, 16),
			blockOneColor : parseInt(configData.blockOneColor, 16),
			blockTwoColor : parseInt(configData.blockTwoColor, 16),
			blockThreeColor : parseInt(configData.blockThreeColor, 16),
			blockFourColor : parseInt(configData.blockFourColor),
			blockFiveColor : parseInt(configData.blockFiveColor),
			blockSixColor : parseInt(configData.blockSixColor),
			blockSevenColor : parseInt(configData.blockSevenColor),
			blockEightColor : parseInt(configData.blockEightColor),
			blockNineColor : parseInt(configData.blockNineColor),
			blockTenColor : parseInt(configData.blockTenColor),
			blockElevenColor : parseInt(configData.blockElevenColor),
			blockTwelveColor : parseInt(configData.blockTwelveColor)

		}, function() {
			console.log("send successful!");
		}, function() {
			console.log("send failed!");
		});
	}
});
