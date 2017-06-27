private void ShowProductNotification(int product_id, String product_information) {
	// 建立震動效果，陣列中元素依序為停止、震動的時間，單位是毫秒
	long[] vibrate_effect = {1000, 500, 1000, 400, 1000, 300, 1000, 200, 1000, 100};

	int notifyID = product_id;    // 通知的識別號碼
	final int requestCode = notifyID;   // PendingIntent的Request Code

	final Intent intent = new Intent(getApplicationContext(), MainActivity.class);
	final int flags = PendingIntent.FLAG_UPDATE_CURRENT; // ONE_SHOT：PendingIntent只使用一次；CANCEL_CURRENT：PendingIntent執行前會先結束掉之前的；NO_CREATE：沿用先前的PendingIntent，不建立新的PendingIntent；UPDATE_CURRENT：更新先前PendingIntent所帶的額外資料，並繼續沿用

	final TaskStackBuilder stackBuilder = TaskStackBuilder.create(getApplicationContext()); // 建立TaskStackBuilder
	stackBuilder.addParentStack(RoutePlanningActivity.class); // 加入目前要啟動的Activity，這個方法會將這個Activity的所有上層的Activity(Parents)都加到堆疊中
	stackBuilder.addNextIntent(intent); // 加入啟動Activity的Intent

	final PendingIntent pendingIntent = stackBuilder.getPendingIntent(requestCode, flags); // 取得PendingIntent

	//通知什麼商品特價
	final NotificationManager notificationManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE); // 取得系統的通知服務
	final Notification notification =
			new Notification.Builder(getApplicationContext())
							.setSmallIcon(R.drawable.onsale)
							.setContentTitle("附近有商品特價喔！")
							.setContentText(product_information)
							.setContentIntent(pendingIntent)
							.setPriority(Notification.PRIORITY_HIGH)
							.setVibrate(vibrate_effect)
							.build(); // 建立通知

	notificationManager.notify(notifyID, notification); // 發送通知

	//通知有商品特價，請查看　
   notifyID = IBeaconGlobal.PRODUCT_PUSH_ID;

	final Notification notification_information =
	new Notification.Builder(getApplicationContext())
			.setSmallIcon(R.drawable.onsale)
			.setContentTitle("附近有商品特價喔！")
			.setContentText("請查看以下特價商品")
			.setContentIntent(pendingIntent)
			.setPriority(Notification.PRIORITY_HIGH)
			.setVibrate(vibrate_effect)
			.build(); // 建立通知

	notificationManager.notify(notifyID, notification_information); // 發送通知
}