#
# Be sure to run `pod lib lint goedle_io_sdk.podspec' to ensure this is a
# valid spec before submitting.
Pod::Spec.new do |s|
  s.name             = 'goedle_io_sdk'
  s.version          = '0.2.0'
  s.summary          = 'iOS SDK for the goedle.io service'
  s.description      = <<-DESC
goedle.io predicts the future behavior of your customers. This SDK has basic tracking methods and uses the APPLE IDFA. It is the beginning of you personal AI and your access to Machine Learning.
                       DESC
  s.homepage         = 'https://github.com/goedleIO/goedle_io_sdk_ios/'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'goedle.io GmbH' => 'marc@goedle.io' }
  s.source           = { :git => 'https://github.com/goedleIO/goedle_io_sdk_ios/', :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/goedle_io'
  s.ios.deployment_target = '8.0'
  s.source_files = 'goedle_io_sdk/Classes/GoedleSdkiOS.h'
  s.vendored_library = 'goedle_io_sdk/Classes/libGoedleSdkiOS.a' 
end
