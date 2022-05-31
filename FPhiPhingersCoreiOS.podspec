#
#  Be sure to run `pod spec lint FPhiSelphIDWidgetiOSLight.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name         = "FPhiPhingersCoreiOS"
  s.version      = "8.0.11"
  s.summary      = "Phingers widget for Fingerprint detection and recognition"
  s.description  = <<-DESC
                  Phingers widget for Fingerprint detection and recognition.
                  DESC
  s.homepage     = "http://www.facephi.com"
  s.license      = {
                    :type => "Commercial", 
                    :text => <<-LICENSE
                    © Facephi 2022. All rights reserved.
                    LICENSE
                  }
  s.authors      = { "FacePhi" => "support@facephi.com" }
  
  s.platform     = :ios, "11.0"
  s.source       = { :git => "https://github.com/facephi/phingers-core-framework.git" }

  s.ios.vendored_frameworks = './Frameworks/OnyxCamera/8.0.11/OnyxCamera.framework', './Frameworks/OnyxCore/8.0.11/onyx-camera.framework'
  s.requires_arc            = true
  s.xcconfig                = { 'FRAMEWORK_SEARCH_PATHS' => '$(inherited)', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 armv7' }
  s.pod_target_xcconfig     = { 'ENABLE_BITCODE' => 'NO', 'OTHER_LDFLAGS' => '-lObjC', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 armv7' }
  s.resource_bundles        = { 'OnyxCamera' => ['Assets/*.*'] }
  s.frameworks              = 'CoreMedia', 'AVFoundation', 'AssetsLibrary'
  s.dependency                'OpenCV', '3.4.5'
  s.dependency                'TensorFlowLiteObjC'
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 armv7' }                             

end
