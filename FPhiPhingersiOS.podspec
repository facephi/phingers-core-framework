#
#  Be sure to run `pod spec lint FPhiSelphIDWidgetiOSLight.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name         = "FPhiPhingersiOS"
  s.version      = "1.0.0"
  s.summary      = "Phingers widget for Fingerprint detection and recognition"
  s.description  = <<-DESC
                  Phingers widget for Fingerprint detection and recognition.
                  DESC
  s.homepage     = "http://www.facephi.com"
  s.license      = {
                    :type => "Commercial", 
                    :text => <<-LICENSE
                    © Facephi 2021. All rights reserved.
                    LICENSE
                  }
  s.authors      = { "FacePhi" => "support@facephi.com" }
  
  s.platform     = :ios, "10.0"
  s.source       = { :git => "https://github.com/facephi/phingers-framework.git", :tag => "#{s.version}" }

  s.vendored_frameworks = 'Frameworks/*.framework'
  s.frameworks          = 'CoreMedia','AVFoundation','AssetsLibrary'

  s.dependency 'OpenCV', '3.4.5'
  s.dependency 'TensorFlowLiteObjC'      

  s.resource_bundles = {
    'PhingersCamera' => ['Assets/*.*']
  }

  s.requires_arc      = true
  s.static_framework  = true

  s.xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => '$(inherited)',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }

  s.pod_target_xcconfig = {
    'ENABLE_BITCODE' => 'NO',
    'OTHER_LDFLAGS' => '-lObjC',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }

  s.user_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }

end